CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS = AaptAssets.o \
	Command.o \
	CrunchCache.o \
	FileFinder.o \
	Main.o \
	Package.o \
	StringPool.o \
	XMLNode.o \
	ResourceFilter.o \
	ResourceIdCache.o \
	ResourceTable.o \
	Images.o \
	Resource.o \
    pseudolocalize.o \
    SourcePos.o \
	WorkQueue.o \
    ZipEntry.o \
    ZipFile.o \
	qsort_r_compat.o

LIBS =

TARGET =	aapt

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
