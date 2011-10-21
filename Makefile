################################################################################
# Configuration du Makefile                                                    #
################################################################################

# Dossier source
SRC_DIR         = ./src/
# Dossier objets
OBJ_DIR         = ./obj/
# Dossier dépendances
DEP_DIR         = ./dept/
# Dossier executable
BIN_DIR         = ./bin/

# Nom de l'executable
BIN             = ding

# Libs
LIB_DIR         = ./
# Includes
INC_DIR         = ./include/

# Compilation C
CC      = g++
# Compilation C++
CPP     = g++
# Linker
LD      = g++
# Commande Flex
FLEX    = flex
# Commande Bison
BISON   = bison -d

# Flags CPP
CPPFLAGS        = -I$(INC_DIR) -g -Wall -pipe
# Flags C
CFLAGS          = -I$(INC_DIR) -g -Wall -pipe
# Flags du linker
LDFLAGS = -L$(LIB_DIR) -lfl

################################################################################
# NE RIEN CHANGER APRÈS CETTE LIGNE                                            #
################################################################################

SRCS_CPP        = $(wildcard $(SRC_DIR)*.cpp)
SRCS_C          = $(wildcard $(SRC_DIR)*.c)
SRCS_L          = $(wildcard $(SRC_DIR)*.l)
SRCS_Y          = $(wildcard $(SRC_DIR)*.y)

#Liste des dépendances .cpp, .c ==> .d
DEPS    = $(SRCS_CPP:$(SRC_DIR)%.cpp=$(DEP_DIR)%.d) $(SRCS_C:$(SRC_DIR)%.c=$(DEP_DIR)%.d)

#Liste des objets : .cpp, .c, .y, .l ==> .o
OBJS    = $(SRCS_CPP:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o) $(SRCS_C:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) \
          $(SRCS_Y:$(SRC_DIR)%.y=$(OBJ_DIR)%.o) $(SRCS_L:$(SRC_DIR)%.l=$(OBJ_DIR)%.o)

#Rules
all: $(BIN_DIR)/$(BIN)

#To executable
$(BIN_DIR)/$(BIN): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(LD) $+ -o $@ $(LDFLAGS)
        
#To Objets
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -o $@ -c $<

#To SRC
$(SRC_DIR)%.c : $(SRC_DIR)%.l 
	$(FLEX) -o $@ $<

$(SRC_DIR)%.c : $(SRC_DIR)%.y
	mkdir -p $(INC_DIR)
	$(BISON) -o $@ $<
	mv -v $(SRC_DIR)parser.h $(INC_DIR)parser.hpp

#Gestion des dépendances
$(DEP_DIR)%.d: $(SRC_DIR)%.c
	mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) -MM -MD -o $@ $<

$(DEP_DIR)%.d: $(SRC_DIR)%.cpp
	mkdir -p $(DEP_DIR)
	$(CPP) $(CPPFLAGS) -MM -MD -o $@ $<

-include $(DEPS)

.PHONY: clean distclean


run: $(BIN_DIR)/$(BIN)
	$(BIN_DIR)/$(BIN)

#Rangement des fichiers
store:
	mkdir -p $(INC_DIR)
	mkdir -p $(SRC_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(DEP_DIR)
	mv -v *.hpp $(INC_DIR)
	mv -v parser.h $(INC_DIR)
	mv -v *.cpp $(SRC_DIR)
	mv -v lexer.l $(SRC_DIR)
	mv -v parser.y $(SRC_DIR)
	mv -v *.o $(OBJ_DIR)
	mv -v *.d $(DEP_DIR)


gdb: $(BIN_DIR)/$(BIN)
	gdb $(BIN_DIR)/$(BIN)

valgrind: $(BIN_DIR)/$(BIN)
	valgrind $(BIN_DIR)/$(BIN)

clean:
	rm -f $(OBJ_DIR)*.o $(SRC_DIR)*~ $(DEP_DIR)*.d *~ $(BIN_DIR)/$(BIN)

distclean: clean
	rm -f $(BIN_DIR)/$(BIN)

tar: clean
	tar -cvzf ../${shell basename `pwd`}.tgz ../${shell basename `pwd`}

