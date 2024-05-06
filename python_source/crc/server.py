import crc
import socket
from utils import text_from_bits

if __name__ == '__main__':
    HOST = '127.0.0.1'
    PORT = 65432

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()

        while True:
            conn, addr = s.accept()

            with conn:
                print(f'Установлено соединение. Клиент {addr}')
                while True:
                    data = conn.recv(1024).decode()
                    if not data:
                        break

                    print(f'Получено сообщение:\n{data}')
                    decoded_data = crc.decode(data)

                    if decoded_data != '0x00001':
                        plain_text = text_from_bits(decoded_data)
                        print(f'Полученное сообщение: {plain_text}\n\n')
                        conn.sendall(plain_text.encode())
                    else:
                        print(f'ОШИБКА: 0x00001\n\n')
                        conn.sendall('0x00001'.encode())
