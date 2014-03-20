
SHARED_LIB := test
SHARED_LIB_VER = 1
SHARED_LIB_NAME :=lib$(SHARED_LIB).so 
SHARED_LIB_REAL_NAME :=$(addsuffix  .$(SHARED_LIB_VER), $(SHARED_LIB_NAME))

LD_FLAGS := -l$(SHARED_LIB)
LD_PATH := -L.
C_FLAGS :=
C_INC := -I.

SHARED_OBJS := a.o b.o
MAIN_OBJS := main.o
TARGET := main


all:$(SHARED_LIB_REAL_NAME) $(MAIN_OBJS)
	$(CC) $(C_INC) $(LD_PATH) -Wall $(MAIN_OBJS) $(LD_FLAGS) -o $(TARGET)

$(SHARED_LIB_REAL_NAME):$(SHARED_OBJS)
	$(CC) -shared -Wl,-soname,libtest.so -o $@ $?
	ln -sf $(SHARED_LIB_REAL_NAME) $(SHARED_LIB_NAME)

$(SHARED_OBJS):%.o:%.c
	$(CC) -c -Wall -fpic $< -o $@


$(MAIN_OBJS):%.o:%.c
	$(CC) -c -Wall -o $@ $<


.PHONY:clean

clean:
	-rm *.o
	-rm libtest.so*
	-rm $(TARGET)
