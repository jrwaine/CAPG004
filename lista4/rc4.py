import sys
import numpy as np

i = 0
j = 0

#-------------------------------------------------------------------
# Funcao para transformar {a, b, c, ... z} para {0, 1, 2, ..., 25}:
def map_num (char):
   return ord(char)

#-------------------------------------------------------------------
# Funcao para transformar {0, 1, 2, ..., 25} para {a, b, c, ... z}:
def map_char (num):
   return chr(num)

def KSA (chave, S, N):
    j = 0
    for i in range(0, N):
        S[i] = i
    for i in range(0, N):
        j = (j + S[i] + map_num(chave[i % len(chave)])) % N
        #j = (j + S[i] + chave[i % len(chave)]) % N
        S[i], S[j] = S[j], S[i]

def PRGA (S, N):
    global i
    global j
    i = (i+1)%N
    j = (j+S[i])%N
    S[i], S[j] = S[j], S[i]
    return (S[(S[i]+S[j]) % N])

#-------------------------------------------------------------------

file_out = open(sys.argv[3], 'w')
chave = sys.argv[2]
N = 256
S = [0] * N

#chave = [(257-x) for x in range(0, 256)]
#chave[0] = 256

#print(S)
KSA(chave, S, N)
#print(S)


with open(sys.argv[1]) as file: 
   for line in file:
      for char in line:
         file_out.write(map_char(map_num(char)^PRGA(S, N))) 
      file_out.write("\n")
file_out.close()

