import bmw512_hash, os, sys, time, binascii

#result should be:
#block b'00000018dc40662d792b9c5432150a7cb017ded675e87fb3842185c486d8c40c'
#nonce was 658301

def gennonce(decnonce):
  hexnonce = str(hex(decnonce)).replace('0x','')
  while len(hexnonce) < 8:
    hexnonce = '0' + hexnonce
  return str(hexnonce)

#main
header = '00112233'
while len(header) < 152:
  header = '00' + header

target = "000000ffff000000000000000000000000000000000000000000000000000000"
targetbin = binascii.unhexlify(target)
nonce = 0
while True:
  
  complete_header = str(header) + str(gennonce(nonce))
  hashbin = bmw512_hash.getPoWHash(binascii.unhexlify(complete_header))[::-1]

  if hashbin < targetbin:
     print ('block ' + str(binascii.hexlify(hashbin)))
     print ('nonce was ' + str(nonce))
     sys.exit(0)

  if (nonce % 1024 == 0):
     fnonce = str(hex(nonce)).replace('0x','')
     while len(fnonce) < 8:
      fnonce = '0' + fnonce
     print (fnonce)

  nonce += 1

