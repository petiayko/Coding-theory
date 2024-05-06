GEN_POLY = '1011'


def encode(data, gen_poly=GEN_POLY):
    remainder = __div(data + '0' * (len(gen_poly) - 1), gen_poly, )
    codeword = data + remainder
    return codeword


def decode(data, gen_poly=GEN_POLY):
    remainder = __div(data, gen_poly)

    if remainder == '0' * (len(gen_poly) - 1):
        return data[:-len(gen_poly) + 1]

    return '0x00001'


def __xor(a: str, b: str) -> str:
    return ''.join(['0' if a[i] == b[i] else '1' for i in range(1, len(b))])


def __div(divisible: str, divisor: str) -> str:
    pick = len(divisor)
    tmp = divisible[:pick]

    while pick < len(divisible):
        if tmp[0] == '1':
            tmp = __xor(divisor, tmp) + divisible[pick]
        else:
            tmp = __xor('0' * pick, tmp) + divisible[pick]
        pick += 1

    if tmp[0] == '1':
        tmp = __xor(divisor, tmp)
    else:
        tmp = __xor('0' * pick, tmp)

    checkword = tmp
    return checkword
