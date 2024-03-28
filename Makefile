# Compilation flags
CFLAGS = -Wall -Wextra -ansi -pedantic

# Source files directory
SRCDIR = src

# Output directory
OUTDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Executable name
EXECUTABLE = minesweeper

all: create_home_dir $(OUTDIR)/$(EXECUTABLE)

$(OUTDIR)/$(EXECUTABLE): $(SOURCES)
	@echo "Building executable: $@"
	@mkdir -p $(OUTDIR)  # Create output directory if it doesn't exist
	@echo "Creating minesweeper folder at $(MINESWEEPER_FOLDER)"  # Add this line
	gcc $(CFLAGS) -o $@ $^
	@echo "Build complete :)"

create_home_dir:
	@echo "Creating directory in home"
	@if mkdir -p $(HOME)/new_directory; \
		then \
		echo "Directory created in home"; \
		else \
		echo "Failed to create directory in home"; \
		exit 1; \
	fi



.PHONY: clean
clean:
	@echo "Cleaning up"
	@rm -rf $(OUTDIR)
	@echo "Cleanup complete"