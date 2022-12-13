MyProject : port.o port.c
	gcc port.o -o port
	./a.exe
MyProject : port.c
	gcc -c port.c -o port.o
installemsdk: 
	cd .. && git clone https://github.com/emscripten-core/emsdk.git
	cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc port.c -o port.html
	npm i http-server -g
runserver:
	  http-server