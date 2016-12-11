#
# Installation script for B.I.A.G.R.A library
#    BIbliotecA de proGRamacion cientificA
#    (c) 1998 Jose Angel de Bustos Perez
#          <jadebustos@gmail.com>
# This software is licensed under GPLv2:
#     http://www.gnu.org/licenses/gpl-2.0.html
#

# Compiler
CC=gcc

# Object files
EXTOBJ=o

# version
BIAVERSION=1.0.0

# Library name
LIBRARY=libbiagra.a

# includes dir
INCLUDESDIR=/usr/include/biagra

# examples dir
EXAMPLESDIR=/usr/share/biagra-$BIAVERSION

case $1 in
	
  static) # Static library installation

  echo "B.I.A.G.R.A static library installation"
  mkdir -p $INCLUDESDIR

  for i in *.h
  do
    cp $i $INCLUDESDIR
  done

  for i in *.c
  do
    FILENAME=$(basename $i c)
    OBJFILENAME=$FILENAME$EXTOBJ
    echo "Compiling $i ..."
    $CC -c $i -o $OBJFILENAME
  done
  echo "Creating static library $LIBRARY-$BIAVERSION ..."

  for i in *.o
  do
    ar cru $LIBRARY-$BIAVERSION $i
    rm $i
  done

  echo "Creating library index ..."
  ranlib $LIBRARY-$BIAVERSION
  mv $LIBRARY-$BIAVERSION /usr/lib/$LIBRARY-$BIAVERSION
  rm -f /usr/lib/$LIBRARY
  rm -f $LIBRARY
  ln -s /usr/lib/$LIBRARY-$BIAVERSION /usr/lib/$LIBRARY

  echo "Copying examples ..."
  mkdir -p $EXAMPLESDIR
  cp -prf examples/* $EXAMPLESDIR;;

  uninstall)
    echo "Removing header files ..."
    rm -Rf $INCLUDESDIR
    echo "Removing example files ..."
    rm -Rf $EXAMPLESDIR
    echo "Removing library ..."
    rm -f /usr/lib/$LIBRARY-$BIAVERSION /usr/lib/$LIBRARY;;

  *)
  echo "Argument required: static";;

esac

