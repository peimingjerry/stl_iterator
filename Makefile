
EXE := test
OBJ_DIR := ./obj
RM := rm -rf 
LD := g++ 
CC := g++ 
#CC_FLAG := -DUSE_STL_ALGO
CC_FLAG := 

$(EXE): $(OBJ_DIR)/main.o
    $(LD) -o $@ $<

$(OBJ_DIR)/main.o : main.cpp iterator_algo.h iterator_traits.h  list.h
    $(CC) $(CC_FLAG) -o $@ -c $^

clean:
    $(RM) $(EXE) $(OBJ_DIR)/*.o
