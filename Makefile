CC=g++
SRCS=src/blackhole_funcs.cpp src/graphics/animation.cpp src/graphics/animator_controller.cpp src/graphics/imageBase.cpp src/graphics/image.cpp src/graphics/spritesheet.cpp src/graphics/tilemap.cpp src/graphics/window.cpp src/graphics/camera.cpp
HEADERS=include/graphics/*.h
HEADERDIR=include
OBJDIR=obj
LIBDIR=lib
OUTLIB=libblackhole.so
INCLUDEDIR=/usr/local/include/blackhole
CFLAGS=-lpthread -lSDL2main -lSDL2 -lSDL_mixer -I$(HEADERDIR)

exec : $(OBJDIR) $(LIBDIR) $(INCLUDEDIR)
	$(CC) -c -Wall -fpic $(SRCS) $(CFLAGS)
	mv *.o $(OBJDIR)
	$(CC) -shared -o $(LIBDIR)/$(OUTLIB) $(OBJDIR)/*.o
	cp -r $(HEADERDIR)/* $(INCLUDEDIR)
	cp -r $(LIBDIR)/$(OUTLIB) /usr/local/lib

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBDIR):
	mkdir $(LIBDIR)

$(INCLUDEDIR):
	mkdir $(INCLUDEDIR)

.PHONY : clean
clean : $(OBJS)
		find . -name "*~" -exec rm {} \;
		find . -name "#*#" -exec rm {} \;
		find . -name "*.gch" -exec rm {} \;
