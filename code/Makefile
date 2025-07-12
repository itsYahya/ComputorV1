GCC= gcc
OUT= computor
BUILD= build

HEADERSFILES_ = $(wildcard inc/*.h) $(wildcard inc/**/*.h)

HEADERSFILES = $(subst inc/, , $(HEADERSFILES_:.h=)) 
				
HEADERS := $(addprefix inc/, $(HEADERSFILES:=.h))

FILES_ = $(wildcard *.c) $(wildcard src/*.c) $(wildcard src/**/*.c)

FILES__ := $(subst src/, , $(FILES_))

FILES = $(FILES__:%.c=%)

OBJS := $(addprefix $(BUILD)/, $(FILES:=.o))

all : $(OUT)
	
$(OUT) : $(OBJS) $(HEADERS)
	$(GCC) $(OBJS) -o $(OUT)

$(BUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(GCC) -c $< -o $@ $(INC)

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(OUT)

re : fclean all

.PHONY : re fclean clean all