def cipher_vig_c(char, key_c):
    if(char >= 'a' and char <= 'z'):
        dchar = ord(char) + ord(key_c) + 26 - 2 * ord('a') # 2 because key_c sums 'a' too
        dchar %= 26
        dchar += ord('a')
        return chr(dchar)
    return char

def cipher_vig(txt, key):
    txt_c = ''
    k = 0    
    key = key.lower()
    txt = txt.lower()    
    for i in range(0, len(txt)):
        txt_c += cipher_vig_c(txt[i], key[k % len(key)])
        if(txt[i].isalpha()):
            k += 1    
    return txt_c

def dcipher_vig_c(char, key_c):
    if(char >= 'a' and char <= 'z'):
        dchar = ord(char) - ord(key_c) + 26
        dchar %= 26
        dchar += ord('a')
        return chr(dchar)
    return char

def dcipher_vig(txt, key):
    txt_d = ''
    k = 0
    key = key.lower()
    txt = txt.lower()    
    for i in range(0, len(txt)):
        txt_d += dcipher_vig_c(txt[i], key[k % len(key)])
        if(txt[i].isalpha()):
            k += 1    
    return txt_d



FILENAME_IN = 'gonzaguinha.txt'
FILENAME_OUT = 'gonzaguinha_crip.txt'
KEY = 'gonzaga'

txt = ''
with open(FILENAME_IN, 'r') as f:
    txt = f.read()  

txt_c = cipher_vig(txt, KEY)

with open(FILENAME_OUT, 'w') as f:
    f.write(txt_c)  


