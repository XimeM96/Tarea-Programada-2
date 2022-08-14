FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ $(FLAGS) src/pago.cpp -o bin/pago.o
	g++ $(FLAGS) src/reporteFinal.cpp -o bin/reporteFinal.o
	g++ $(FLAGS) src/jerarquiaDeEmpleados.cpp -o bin/jerarquiaDeEmpleados.o
	g++ -g -o bin/tarea2 bin/empleado.o bin/pago.o bin/jerarquiaDeEmpleados.o bin/reporteFinal.o bin/main.o 

test:

	mkdir -p bin
	g++ $(FLAGS) tests/test_archivos.cpp -o bin/test_archivos.o
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/pago.cpp -o bin/pago.o
	g++ $(FLAGS) src/reporteFinal.cpp -o bin/reporteFinal.o	
	g++ $(FLAGS) src/jerarquiaDeEmpleados.cpp -o bin/jerarquiaDeEmpleados.o		
	g++ -g -o bin/tests bin/test_archivos.o bin/pago.o bin/empleado.o bin/reporteFinal.o bin/jerarquiaDeEmpleados.o -lgtest -lgtest_main -lpthread 

	
clean:
	rm -Rf bin
	rm -Rf *.csv