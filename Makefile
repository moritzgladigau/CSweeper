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

all: $(OUTDIR)/$(EXECUTABLE)

# Get the current user's username
USER := $(USER)

# Print the username
$(info ---> Das ist der Benutzername: $(USER))

# Define the path to the minesweeper folder
MINESWEEPER_FOLDER = /Users/$(USER)/Library/Application\ Support/minesweeper

$(OUTDIR)/$(EXECUTABLE): $(SOURCES)
	@echo "Building executable: $@"
	@mkdir -p $(OUTDIR)  # Create output directory if it doesn't exist
	@echo "Creating minesweeper folder at $(MINESWEEPER_FOLDER)"  # Add this line
	@mkdir -p $(MINESWEEPER_FOLDER) # Create minesweeper folder
	gcc $(CFLAGS) -o $@ $^
	@echo "Build complete :)"

.PHONY: clean
clean:
	@echo "Cleaning up"
	@rm -rf $(OUTDIR)
	@echo "Cleanup complete"