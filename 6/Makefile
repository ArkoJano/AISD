# Dodanie dodatkowych rozszerzen
.SUFFIXES: .c .cpp .o .x .h 

# aktualna lokalizacja
DIR = `basename $(CURDIR)`

#########################################################################

###################     PRZYPISANIE NAZW PLIKOW     #####################

#########################################################################


# nazwy plikow 
NAME1 = Main_array
NAME2 = Main_list
NAME3 = List
NAME4 = LinkedList
NAME5 = ArrayList
NAME6 = ArrayBasedStack
NAME7 = ListBasedStack




# nazwy plikow wykonywalnych
EXEC1    = $(NAME1).x 
EXEC2    = $(NAME2).x 
EXEC3    = $(NAME3).x 
EXEC4    = $(NAME4).x 
EXEC5    = $(NAME5).x 
EXEC6    = $(NAME6).x 
EXEC7    = $(NAME7).x 


# obiekt biblioteki
OBJS1    = $(NAME1).o
OBJS2    = $(NAME2).o
OBJS3    = $(NAME3).o
OBJS4    = $(NAME4).o
OBJS5    = $(NAME5).o
OBJS6    = $(NAME6).o
OBJS7    = $(NAME7).o



# Pliki naglowkowe
HEADS2 = $(NAME2).h
HEADS3 = $(NAME3).h
HEADS4 = $(NAME4).h
HEADS5 = $(NAME5).h
HEADS6 = $(NAME6).h
HEADS7 = $(NAME7).h



#########################################################################

########     UNIWERSALNY WZORZEC TWORZENIA PLIKOW OBIEKTOWYCH    ########

#########################################################################

# INFO:
# Znak % oznacza wzorzec, tzn. dowolny ciag znakow, ktore tworza rdzen nazwy 
# pliku. 
# Zmienna wewnetrzna $< oznacza pierwszy prerekwizyt, tu: nazwe odpowiedniego 
# pliku z rozszerzeniem .c, ktory nalezy uaktualnic aby otrzymac plik .o. 

# tworzy akutalnie wymagane pliki obiektowe OBJS#
%.o: %.cpp %.h
	$(CO) $(CFLAGS) -c $<
# Jak wyzej, ale bez zaleznosci od plikow naglowkowych
%.o: %.cpp
	$(CO) $(CFLAGS) -c $<



# eliminacja ewentualnej mozliwosci wykonania pliku "all"
.PHONY: all

# aktualizacja wszystkich plikow wykonywalnych
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5) $(EXEC6) $(EXEC7)  



#########################################################################

########################     URUCHAMIANIE     ###########################

#########################################################################


# Uruchomienie 
run_array: $(EXEC1)
	./Main_array.x 
 
run_list: $(EXEC2)
	./Main_list.x


#########################################################################

#####################     TWORZENIE BIBLIOTEK     #######################

#########################################################################


# wykorzystywany kompliator
CO = g++
#wykorzystywany linker
LD = $(CO)

# flagi kompilatora wykorzystywane podczas kompilacji 
CFLAGS = # -Wall -pedantic 


#########################################################################

####################     KOMPILACJA PLIKOW .x     #######################

#########################################################################


# Main_array.x
$(EXEC1): $(OBJS1) $(OBJS3) $(OBJS5) $(OBJS6)  
	$(CO) $(OBJS1) $(OBJS3) $(OBJS5) $(OBJS6) $(CFLAGS) -o $(EXEC1) 
# Main_list.x
$(EXEC2): $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS7)  
	$(CO) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS7) $(CFLAGS) -o $(EXEC2) 


#########################################################################

###########################     RESZTA     ##############################

#########################################################################

# eliminacja ewentualnej mozliwosci wykonania pliku "clean" lub "tar" 
.PHONY: clean tar

# funkcja usuwajaca zbedne elementy o danych rozszerzeniach/nazwach
clean:                                                     
	rm -f *.o *.a *.x a.out ./lib/*.a ./lib/*.so;


# funkcja archiwizujaca wszystkie pliki po pozbyciu sie zbednych
# archiwum o rozszerzeniu .tar.gz i nazwia katalogu w ktorym sie znajduje
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

