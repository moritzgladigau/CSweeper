class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "de9d89c4dafdf79a3cf67de79766031b04efadd9f8ce0cb584e39e7e36669154"
  # sha256 :no_check

  depends_on "gcc" # Abhängigkeit von GCC
  
  def install
    # Create the bin directory if it doesn't exist
    bin.mkpath

    # Build the executable
    system "make"

    # Install the executable to the bin directory
    bin.install "bin/minesweeper"

    # Create the minesweeper directory in the Application Support directory
    (File.expand_path("~/Library/Application Support/minesweeper")).mkpath
  end

  def uninstall
    # Entfernen Sie das ausführbare Spiel
    rm bin/"minesweeper"

    # Remove the minesweeper directory
    rm_rf File.expand_path("~/Library/Application Support/minesweeper")

    # Weitere Dateien oder Verzeichnisse entfernen, falls 
vorhanden
    # Zum Beispiel Konfigurationsdateien, Datenverzeichnisse usw.
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
