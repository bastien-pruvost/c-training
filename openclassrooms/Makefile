# Nom de l'exécutable
EXEC = bin/main

# Répertoires
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Recherche automatique des fichiers source et génération des fichiers objets
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

# Règle principale : génération de l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compilation de chaque fichier .c en fichier .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj/ si non existant
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Nettoyage avancé
fclean: clean

# Recompile tout depuis zéro
re: fclean $(EXEC)

run: $(EXEC)
	./$(EXEC)

# Indiquer que ces règles ne sont pas des fichiers
.PHONY: clean fclean re
