from distutils.core import setup, Extension

bmw512_hash_module = Extension('bmw512_hash',
                               sources = ['bmw512.c',
                                          'bmw512_module.c',
                                          'sph/bmw.c'],
                            include_dirs=['.', './sph'])

setup (name = 'bmw512_hash',
       version = '1.0',
       ext_modules = [bmw512_hash_module])
