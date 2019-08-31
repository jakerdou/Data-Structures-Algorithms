LD = $(shell which g++)
CXX = $(shell which g++)
override CXXFLAGS += -std=c++11 -Wall
EXE = Project3.out
OBJS = main.o Song.o Library.o TitleCompare.o ArtistCompare.o AlbumCompare.o GenreCompare.o YearCompare.o
DEPS = $(addprefix.,$(OBJS:.o=.d))

$(EXE): $(DEPS) $(OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@
	
.%.d: %.cpp
	@$(RM) $@; \
	$(CXX) -MM -MF $@ -MT "$(<:.cpp=.o) $@" -c $(CPPFLAGS) $<
	
$(OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	
-include $(DEPS)

.PHONY: clean
clean:	
	$(RM) $(OBJS) $(DEPS) $(EXE)

.PHONY: run
run: $(EXE)
	./$(EXE) $(LIBRARY_FILE)

	
