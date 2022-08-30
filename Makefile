ifndef seed
seed = 0
endif

.PHONY: all
all: build bench diff clean

.PHONY: build
build:
	c++ -Wall -Werror -Wextra -D STD -std=c++98 main.cpp -o std.out
	c++ -Wall -Werror -Wextra -std=c++98 main.cpp -o ft.out

.PHONY: bench
bench:
	time ./std.out $(seed) > std.perf
	time ./ft.out $(seed) > ft.perf

.PHONY: diff
diff:
	diff std.perf ft.perf

.PHONY:
clean:
	@rm std.out ft.out
	@rm std.perf ft.perf