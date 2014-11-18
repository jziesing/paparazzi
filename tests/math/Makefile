# Copyright (C) 2014 Piotr Esden-Tempski
#
# This file is part of paparazzi.
#
# paparazzi is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# paparazzi is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with paparazzi; see the file COPYING.  If not, write to
# the Free Software Foundation, 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.

# The default is to produce a quiet echo of compilation commands
# Launch with "make Q=''" to get full echo

# Make sure all our environment is set properly in case we run make not from toplevel director.
Q ?= @

PAPARAZZI_SRC ?= $(shell pwd)/../..
ifeq ($(PAPARAZZI_HOME),)
PAPARAZZI_HOME=$(PAPARAZZI_SRC)
endif

# export the PAPARAZZI environment to sub-make
export PAPARAZZI_SRC
export PAPARAZZI_HOME

MATHSRC_PATH=$(PAPARAZZI_SRC)/sw/airborne/math
MATHLIB_PATH=$(PAPARAZZI_SRC)/var/build/math

#####################################################
# If you add more testsmutes you add their names here
TESTS = test_pprzmath.run

###################################################
# You should not need to touch the rest of the file

.PHONY: math_shlib test clean all

all: test

math_shlib:
	$(Q)cd $(MATHSRC_PATH); make shared_lib

test: math_shlib $(TESTS)
	$(Q)for i in $(TESTS); do \
	./$$i;	\
	done

%.run: %.c
	$(CC) -L$(MATHLIB_PATH) -lpprzmath -lcheck -I$(MATHSRC_PATH) -I$(PAPARAZZI_SRC)/sw/include $< -o $@

clean:
	$(Q)rm -f $(MATHLIB_PATH)/*.o $(MATHLIB_PATH)/libpprzmath.so
	$(Q)rm -f $(TESTS)
