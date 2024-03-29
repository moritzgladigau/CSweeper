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

# Home directory
MINESWEEPER_FOLDER := $(shell cd ~; pwd)

all: create_home_dir $(OUTDIR)/$(EXECUTABLE)

$(OUTDIR)/$(EXECUTABLE): $(SOURCES)
	@echo "Building executable: $@"
	@mkdir -p $(OUTDIR)  # Create output directory if it doesn't exist
	@echo "Creating minesweeper folder at $(MINESWEEPER_FOLDER)"  # Add this line
	gcc $(CFLAGS) -o $@ $^
	@echo "Build complete :)"


.PHONY: create_home_dir

# Create home directory if it doesn't exist
create_home_dir:
	@echo "Hallo Papa"
	@echo "Creating directory in $(MINESWEEPER_FOLDER)"
	@mkdir -p $(MINESWEEPER_FOLDER)/new_directory || true
	@echo "Directory created in $(MINESWEEPER_FOLDER)/new_directory"



.PHONY: clean
clean:
	@echo "Cleaning up"
	@rm -rf $(OUTDIR)
	@echo "Cleanup complete"