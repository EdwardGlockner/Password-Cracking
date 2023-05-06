CXXFLAGS := -std=c++17
SRCDIR := ./source
INCDIR := ./include
OBJDIR := ./output

pw_attack: $(OBJDIR)/dictionary_attack.o $(OBJDIR)/brute_force.o $(OBJDIR)/rule_based.o $(OBJDIR)/password_comparison.o $(OBJDIR)/main.o
	c++ $(CXXFLAGS) $^ -o $@

$(OBJDIR)/dictionary_attack.o: $(SRCDIR)/dictionary_attack.cpp $(INCDIR)/dictionary_attack.h
	c++ $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/brute_force.o: $(SRCDIR)/brute_force.cpp $(INCDIR)/brute_force.h
	c++ $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/rule_based.o: $(SRCDIR)/rule_based.cpp $(INCDIR)/rule_based.h
	c++ $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/password_comparison.o: $(SRCDIR)/password_comparison.cpp $(INCDIR)/password_comparison.h
	c++ $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o pw_attack
