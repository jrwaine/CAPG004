#obs.: a criptografia é de dois em dois na carta (com algumas exceções)
import operator

def read_parse_file(filename):
    text_dict = dict()
    c1 = 'a'
    c2 = 'a'
    with open(filename) as f:
        while(True):
            c1 = f.read(1)
            if(c1 == '' or c2 == ''):
                break
            while(not(c1.isalnum())):
                c1 = f.read(1)
                if(c1 == '' or c2 == ''):
                    break
            if(c1 == '' or c2 == ''):
                break            
            c2 = f.read(1)
            if(c1 == '' or c2 == ''):
                break                
            while(not(c2.isalnum()) and c2 != ''):
                c2 = f.read(1)
                if(c1 == '' or c2 == ''):
                    break
            if(c1 == '' or c2 == ''):
                break

            pair_key = c1 + c2
            
            if pair_key in text_dict:
                text_dict[pair_key] += 1
            else:
                text_dict[pair_key] = 1

    return text_dict

alphabet_size = 26
in_file_name = './carta.txt'
out_file_name = './carta_decr.txt'

dict_alph = read_parse_file(in_file_name)

dict_sorted = sorted(dict_alph.items(), key=operator.itemgetter(1))

print(dict_sorted)

