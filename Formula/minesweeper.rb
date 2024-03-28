class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "92fea2d7b704a02c27e65aaf81616992e1fee8ab9394a66d2633837be1619699"
  # sha256 :no_check

  depends_on "gcc" # Abhängigkeit von GCC
  
  def install
    # Create the bin directory if it doesn't exist
    bin.mkpath

    # Build the executable
    system "make"

    # Install the executable to the bin directory
    bin.install "bin/minesweeper"

    # Create the minesweeper directory in the user's home directory
    (Dir.home + "/Library/Application Support/minesweeper").mkpath
  end

  def uninstall
    # Entfernen Sie das ausführbare Spiel
    rm bin/"minesweeper"

    # Remove the minesweeper directory
    rm_rf Dir.home + "/Library/Application Support/minesweeper"

    # Weitere Dateien oder Verzeichnisse entfernen, falls 
vorhanden
    # Zum Beispiel Konfigurationsdateien, Datenverzeichnisse usw.
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
