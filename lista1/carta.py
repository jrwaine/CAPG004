#obs.: a criptografia é de dois em dois na carta (com algumas exceções)

import operator

# 1º: '9C' = a, 'CK' = e
# 2º: 'A3' = o, 'P2' = d, '4M': 's'
# 3º: 'B5' = p, 'XT' = i por causa de B5edXTdo 
# 4º: 'K9' = l, 'F7' = v por causa de saK9F7e
# 5º: 'HN' = u (saHNde), 'G3' = t (esG3ao) '659'= r (i659s, espe659o, 659HNa)
# 6º: 'D2' = q (D2uiser, D2ue), 'W2' = n (W2ois, W2a), 'M5' = f (M5oi, M5eito), 
#     'V8' = m (V8esV8a, V8ora, V8ao)
# 7º: '854' = c (v854s, situa854ao, vo854e), '8A' = h (8Aora), '723' = t (lu723ar, fran723o), 
#     '148' = j (148aponeis)
# 8º: 'X1' = b (queX1rada), 
# 9º: '491' = z (infeli491mente), 'NT' = x (eNTiste)
# 10º: correcao '723' = g (franto, amito)
# obs.: caso sejam obtidos resultados diferentes, é provável que a ordem do 
#       'alphabet' seja o causador
alphabet = {
    '659': 'r', # antes por causa de CKW2854A3W2G3659CK (659Ck)
    'K9': 'l', # antes por ccausa do (CK9C)
    'CK': 'e', # antes por causa de CKK9CK (CKK9)
    '9C': 'a',
    'A3': 'o',
    '4M': 's',
    'P2': 'd',
    'XT': 'i',
    'B5': 'p',
    'F7': 'v',
    'HN': 'u',
    'G3': 't',
    'D2': 'q',
    'W2': 'n',
    'M5': 'f',
    'V8': 'm',
    '854': 'c',
    '8A': 'h',
    '723': 'g',
    '148': 'j',
    'X1': 'b',
    '491': 'z',
    'NT': 'x'
}

def read_file(filename):
    txt = str()
    with open(filename, 'r') as f:
        txt = f.read()
    return txt

def write_file(filename, txt):
    with open(filename, 'w') as f:
        txt = f.write(txt)

def get_dict(txt):
    txt_dict = dict()
    for i in range(0, len(txt), 2):
        while(not(txt[i].isalnum()) and i < (len(txt)-2)):
            i += 1
        c_pair = txt[i] + txt[i+1]
        if c_pair in txt_dict:
            txt_dict[c_pair] += 1
        else:
            txt_dict[c_pair] = 1
    return txt_dict

def print_dict_perline(dic):
    for k, v in dic:
        if(v >= 5):
            print(k, ":", v)

def decrypt_text(txt):
    txt_decr = txt
    for k, v in alphabet.items():
        if (v != ''):
            txt_decr = txt_decr.replace(str(k), str(v))
    return txt_decr

in_file_name = './carta.txt'
out_file_name = './carta_decr.txt'

carta = read_file(in_file_name)
dict_alph = get_dict(carta)

dict_sorted = sorted(dict_alph.items(), key=operator.itemgetter(1), reverse=True)
print_dict_perline(dict_sorted)

carta_decr = decrypt_text(carta)
#print(carta_decr)
write_file(out_file_name, carta_decr)