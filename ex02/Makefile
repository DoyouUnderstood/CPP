# Définir le compilateur
CXX = g++
# Définir les options de compilation
CXXFLAGS = -Wall -Wextra -std=c++11

# Nom de l'exécutable
EXEC = bank_app

# Fichiers source
SOURCES = Account.cpp tests.cpp

# Fichiers objet générés
OBJECTS = $(SOURCES:.cpp=.o)

# Règle par défaut
all: $(EXEC)

# Règle de liaison
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour compiler chaque fichier source en fichier objet
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJECTS) $(EXEC)

# Règle pour exécuter le programme
run: $(EXEC)
	./$(EXEC)

# Règle pour afficher les logs
log:
	@cat 19920104_091532.log

.PHONY: all clean run log
