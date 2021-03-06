#
# OpenSSL/crypto/des/Makefile
#

DIR=	des
TOP=	../..
CC=	cc
CPP=	$(CC) -E
INCLUDES=-I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r
RANLIB=		ranlib
DES_ENC=	des_enc.o fcrypt_b.o
# or use
#DES_ENC=	dx86-elf.o yx86-elf.o

CFLAGS= $(INCLUDES) $(CFLAG)
ASFLAGS= $(INCLUDES) $(ASFLAG)
AFLAGS= $(ASFLAGS)

GENERAL=Makefile
TEST=destest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=	cbc_cksm.c cbc_enc.c  cfb64enc.c cfb_enc.c  \
	ecb3_enc.c ecb_enc.c  enc_read.c enc_writ.c \
	fcrypt.c ofb64enc.c ofb_enc.c  pcbc_enc.c \
	qud_cksm.c rand_key.c rpc_enc.c  set_key.c  \
	des_enc.c fcrypt_b.c \
	xcbc_enc.c \
	str2key.c  cfb64ede.c ofb64ede.c ede_cbcm_enc.c des_old.c des_old2.c \
	read2pwd.c

LIBOBJ= set_key.o  ecb_enc.o  cbc_enc.o \
	ecb3_enc.o cfb64enc.o cfb64ede.o cfb_enc.o  ofb64ede.o \
	enc_read.o enc_writ.o ofb64enc.o \
	ofb_enc.o  str2key.o  pcbc_enc.o qud_cksm.o rand_key.o \
	${DES_ENC} \
	fcrypt.o xcbc_enc.o rpc_enc.o  cbc_cksm.o \
	ede_cbcm_enc.o des_old.o des_old2.o read2pwd.o

SRC= $(LIBSRC)

EXHEADER= des.h des_old.h
HEADER=	des_locl.h rpc_des.h spr.h des_ver.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

des: des.o cbc3_enc.o lib
	$(CC) $(CFLAGS) -o des des.o cbc3_enc.o $(LIB)

des_enc-sparc.S:	asm/des_enc.m4
	m4 -B 8192 asm/des_enc.m4 > des_enc-sparc.S

# ELF
dx86-elf.s:	asm/des-586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	(cd asm; $(PERL) des-586.pl elf $(CFLAGS) > ../$@)
yx86-elf.s:	asm/crypt586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	(cd asm; $(PERL) crypt586.pl elf $(CFLAGS) > ../$@)
# COFF
dx86-cof.s: asm/des-586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	(cd asm; $(PERL) des-586.pl coff $(CFLAGS) > ../$@)
yx86-cof.s: asm/crypt586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	(cd asm; $(PERL) crypt586.pl coff $(CFLAGS) > ../$@)
# a.out
dx86-out.s: asm/des-586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	(cd asm; $(PERL) des-586.pl a.out $(CFLAGS) > ../$@)
yx86-out.s: asm/crypt586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	(cd asm; $(PERL) crypt586.pl a.out $(CFLAGS) > ../$@)

files:
	$(PERL) $(TOP)/util/files.pl Makefile >> $(TOP)/MINFO

links:
	@$(PERL) $(TOP)/util/mklink.pl ../../include/openssl $(EXHEADER)
	@$(PERL) $(TOP)/util/mklink.pl ../../test $(TEST)
	@$(PERL) $(TOP)/util/mklink.pl ../../apps $(APPS)

# We need to use force because 'install' matches 'INSTALL' on case
# insensitive systems
FRC.install:
install: FRC.install
	@[ -n "$(INSTALLTOP)" ] # should be set by top Makefile...
	@headerlist="$(EXHEADER)"; for i in $$headerlist ; \
	do  \
	(cp -p $$i $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i; \
	chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i ); \
	done;

tags:
	ctags $(SRC)

tests:

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

depend:
	@[ -n "$(MAKEDEPEND)" ] # should be set by upper Makefile...
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.s *.o *.obj des lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

cbc_cksm.o: cbc_cksm.c des_locl.h
cbc_enc.o: cbc_enc.c des_locl.h ncbc_enc.c
cfb64ede.o: ../../e_os.h cfb64ede.c des_locl.h
cfb64enc.o: cfb64enc.c des_locl.h
cfb_enc.o: ../../e_os.h cfb_enc.c des_locl.h
des_enc.o: des_enc.c des_locl.h ncbc_enc.c
des_old.o: des_old.c
des_old2.o: des_old2.c
ecb3_enc.o: des_locl.h ecb3_enc.c
ecb_enc.o: des_locl.h des_ver.h ecb_enc.c spr.h
ede_cbcm_enc.o: des_locl.h ede_cbcm_enc.c
enc_read.o: ../../e_os.h ../cryptlib.h des_locl.h enc_read.c
enc_writ.o: ../../e_os.h ../cryptlib.h des_locl.h enc_writ.c
fcrypt.o: des_locl.h fcrypt.c
fcrypt_b.o: des_locl.h fcrypt_b.c
ofb64ede.o: des_locl.h ofb64ede.c
ofb64enc.o: des_locl.h ofb64enc.c
ofb_enc.o: des_locl.h ofb_enc.c
pcbc_enc.o: des_locl.h pcbc_enc.c
qud_cksm.o: des_locl.h qud_cksm.c
rand_key.o: rand_key.c
read2pwd.o: read2pwd.c
rpc_enc.o: des_locl.h des_ver.h rpc_des.h rpc_enc.c
set_key.o: des_locl.h set_key.c
str2key.o: des_locl.h str2key.c
xcbc_enc.o: des_locl.h xcbc_enc.c
