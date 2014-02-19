MAJORVERSION = 2
MINVERSION = 0.1
CFLAGS = -O2 -g -Wall --std=gnu++11
LDFLAGS = -Wl,--as-needed


%.fpic.o: %.cpp
	$(CXX) -c -o $@ $(CFLAGS) -fPIC $<

%.o: %.cpp
	$(CXX) -c -o $@ $(CFLAGS) $<


test: test.o gtin.o gtin_chararray.o gtin_checksum.o gtin_data.o
	$(CXX) -o $@ $(LDFLAGS) $+


libgtin.so.$(MAJORVERSION).$(VERSION): gtin.fpic.o gtin_data.fpic.o gtin_checksum.fpic.o gtin_chararray.fpic.o gtin_get_parts.fpic.o
	$(CXX) -o libgtin.so.$(VERSION) -shared -Wl,-soname="libgtin.so.$(MAJORVERSION)" $(LDFLAGS) $+

libgtin.a: gtin.o gtin_data.o gtin_checksum.o gtin_chararray.o gtin_get_parts.o
	ar cvq -o libgtin.a $+

build: libgtin.so.$(VERSION) libgtin.a


install: libgtin.so.$(MAJORVERSION).$(VERSION) libgtin.a gtin.h
	install -d $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)
	mv libgtin.so.$(MAJORVERSION).$(VERSION) $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/
	ln -s /usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so.$(VERSION) $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so
	mv libgtin.a $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/

	install -d $(DESTDIR)/usr/include/
	cp gtin.h $(DESTDIR)/usr/include/gtin.h

uninstall:
	rm -f $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so.$(MAJORVERSION).$(VERSION)
	rm -f $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.so
	rm -f $(DESTDIR)/usr/lib/$(DEB_HOST_MULTIARCH)/libgtin.a
	rm -f $(DESTDIR)/usr/include/libgtin.hpp

clean:
	rm -f *.o libgtin.so.$(VERSION) libgtin.a
