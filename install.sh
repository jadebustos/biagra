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

# Library name
LIBRARY=libbiagra.a

# includes dir
INCLUDESDIR=/usr/include/biagra

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
  echo "Creating static library $LIBRARY ..."

  for i in *.o
  do
    ar cru $LIBRARY $i
    rm $i
  done

  echo "Creating library index"
  ranlib $LIBRARY
  mv $LIBRARY /usr/lib/$LIBRARY;;

  uninstall)
    rm -Rf $INCLUDESDIR;;

  *)
  echo "Argument required: static-install";;

esac

