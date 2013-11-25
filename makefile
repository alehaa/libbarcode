CC = g++
MAJORVERSION = 2
VERSION = 2.0.1
CFLAGS = -O2 -Wall -Wl,--as-needed --std=gnu++11 -g
LDFLAGS = -Wl,--as-needed


%.fpic.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) -fPIC $<

%.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) $<



libgtin.so.$(VERSION): gtin.fpic.o gtin_data.fpic.o gtin_checksum.fpic.o gtin_chararray.fpic.o gtin_get_parts.fpic.o
	$(CC) -o libgtin.so.$(VERSION) -shared -Wl,-soname="libgtin.so.$(MAJORVERSION)" $(LDFLAGS) $+

libgtin.a: gtin.o gtin_data.o gtin_checksum.o gtin_chararray.o gtin_get_parts.o
	ar cvq -o libgtin.a $+

build: libgtin.so.$(VERSION) libgtin.a


install: libgtin.so.$(VERSION) libgtin.a gtin.h
	install -d $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)
	mv libgtin.so.$(VERSION) $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/
	ln -s /usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so.$(VERSION) $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so
	mv libgtin.a $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/

	install -d $(DESTDIR)/usr/include/
	cp gtin.h $(DESTDIR)/usr/include/gtin.h

uninstall:
	rm -f $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so.$(VERSION)
	rm -f $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so
	rm -f $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.a
	rm -f $(DESTDIR)/usr/include/libgtin.hpp

clean:
	rm -f *.o libgtin.so.$(VERSION) libgtin.a
