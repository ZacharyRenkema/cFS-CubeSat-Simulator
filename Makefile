# ==============================================================================
# cFS CubeSat Simulator - top-level build
#
# Wraps cFS's CMake build so it uses OUR mission definitions and OUR apps,
# while leaving the cfs/ submodule completely untouched.
#
# How the path resolution works (see cfs/cfe/cmake/mission_build.cmake):
#   MISSION_SOURCE_DIR  - defaults to the parent of cfs/cfe, i.e. cfs/.
#                         We leave this alone, so NASA's apps, libs, osal
#                         and psp are all found normally inside the submodule.
#   MISSION_DEFS        - defaults to $MISSION_SOURCE_DIR/${MISSIONCONFIG}_defs.
#                         It's a non-FORCE CACHE var, so our -D override wins.
#   CFS_APP_PATH        - extra module search paths, PREPENDED to the default
#                         list. Absolute paths are used as-is. This is how our
#                         apps/ directory gets searched before NASA's.
# ==============================================================================

O             ?= build
DESTDIR       ?= $(CURDIR)/$(O)
BUILDTYPE     ?= debug
INSTALLPREFIX ?= /exe
ARCH          ?= native/default_cpu1
MISSIONCONFIG ?= cubesat

PREP_OPTS := \
	-DMISSIONCONFIG=$(MISSIONCONFIG) \
	-DMISSION_DEFS=$(CURDIR)/$(MISSIONCONFIG)_defs \
	-DCFS_APP_PATH=$(CURDIR)/apps \
	-DSIMULATION=native \
	-DCFE_EDS_ENABLED=OFF \
	-DENABLE_UNIT_TESTS=TRUE \
	-DCMAKE_BUILD_TYPE=$(BUILDTYPE) \
	-DCMAKE_INSTALL_PREFIX=$(INSTALLPREFIX) \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE

.PHONY: prep all install run test clean distclean

$(O)/.prep:
	mkdir -p $(O)
	cd $(O) && cmake $(PREP_OPTS) $(CURDIR)/cfs/cfe
	echo "$(PREP_OPTS)" > $(O)/.prep

prep: $(O)/.prep

all: $(O)/.prep
	$(MAKE) --no-print-directory -C $(O) mission-all

install: $(O)/.prep
	$(MAKE) --no-print-directory -C $(O) DESTDIR=$(DESTDIR) mission-install

run:
	cd $(O)/exe/cpu1 && ./core-cpu1

test: $(O)/.prep
	cd $(O)/$(ARCH) && ctest

clean:
	$(MAKE) --no-print-directory -C $(O) mission-clean

distclean:
	rm -rf $(O)