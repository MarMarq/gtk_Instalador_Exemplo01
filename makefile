#Makefile para arquivo TESTE

CFLAGS=-IC:/msys64/mingw64/include/gtk-3.0 -IC:/msys64/mingw64/bin/../include/gtk-3.0 -IC:/msys64/mingw64/bin/../include/pango-1.0 -IC:/msys64/mingw64/bin/../include/cairo -IC:/msys64/mingw64/bin/../include/gdk-pixbuf-2.0 -IC:/msys64/mingw64/bin/../include/harfbuzz -IC:/msys64/mingw64/bin/../include -IC:/msys64/mingw64/bin/../include/glib-2.0 -IC:/msys64/mingw64/bin/../lib/glib-2.0/include -IC:/msys64/mingw64/bin/../include/freetype2 -IC:/msys64/mingw64/bin/../include/atk-1.0 -IC:/msys64/mingw64/bin/../include/webp -DLIBDEFLATE_DLL -IC:/msys64/mingw64/bin/../include/libpng16 -IC:/msys64/mingw64/bin/../include/pixman-1 -IC:/msys64/mingw64/bin/../include/fribidi -IC:/msys64/mingw64/include/poppler/glib

LIBS=-Lc:/msys64/mingw64/lib -lgtk-3 -LC:/msys64/mingw64/bin/../lib -lgdk-3 -lz -lgdi32 -limm32 -lshell32 -lole32 -luuid -lwinmm -ldwmapi -lsetupapi -lcfgmgr32 -lhid -lwinspool -lcomctl32 -lcomdlg32 -lpangowin32-1.0 -lharfbuzz -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo -lcairo-gobject -lgdk_pixbuf-2.0 -lgio-2.0 -lglib-2.0 -lintl -lgobject-2.0 -lpoppler-glib

all:  
	gcc -o exemplo01 exemplo01_r00.c $(LIBS) $(CFLAGS) -Wall -Wimplicit-function-declaration

exemplo01:

# Observe as opções abaixo e Comente/Descomente o código para o efeito final desejado: 

# Descomente essa opção caso NÃO queria que seja exibida uma janela de console junto com a aplicação
#	gcc -o stepper-1.0.exe stepper_1.0.c $(LIBS) $(CFLAGS) -mwindows

# Descomente essa opção caso queria que seja exibida uma janela de console junto com a aplicação
	gcc -o exemplo01 exemplo01_r00.c $(LIBS) $(CFLAGS) -Wall -Wimplicit-function-declaration


clean:
	rm -fr *.exe 