SYSCONF_LINK = g++
CPPFLAGS     = -O2 -g
LDFLAGS      = 
LIBS         = -lm

DESTDIR = ./
TARGET  = main
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

INCLUDES += -I/home/aleks/hackathon/spdlog/include

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) $(INCLUDES) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)