SUBDIRS = $(wildcard *_*)
export DESTDIR=./obj
export WWWDIR=./www/obj
export USERS=$(shell cat userlist)

all:
	$(foreach dir,$(SUBDIRS),cd $(dir); ./build.zsh $(USERS); cd ..;)

clean:
	$(foreach dir,$(SUBDIRS),cd $(dir); \rm -rf obj; cd ..;)

install:
	mkdir -p $(WWWDIR)
	$(foreach user,$(USERS),mkdir -p $(DESTDIR)/$(user);)
	$(foreach dir,$(SUBDIRS),$(foreach user,$(USERS),/usr/bin/install -p $(dir)/obj/$(user)/* -t $(DESTDIR)/$(user)/;))
	$(foreach user,$(USERS),mv $(DESTDIR)/$(user) $(WWWDIR)/$(user);)

distclean:
	rm -r $(DESTDIR)/*; $(foreach dir,$(SUBDIRS),cd $(dir); \rm -rf obj; cd ..;)
