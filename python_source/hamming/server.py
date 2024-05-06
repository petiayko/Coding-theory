import hamming
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
                    decoded_data, err_pos = hamming.decode(data)

                    if err_pos is not None:
                        print(f'Исправлена ошибка в {err_pos} бите:\n{decoded_data}')

                    plain_text = text_from_bits(decoded_data)
                    print(f'Полученное сообщение: {plain_text}\n\n')
                    conn.sendall(plain_text.encode())
