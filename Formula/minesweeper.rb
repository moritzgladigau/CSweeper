class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "9b8f40517803f8616875a50b84ccf0fb56f45ba7dec1c0353e6ba7e119e7e8a6"
  # sha256 :no_check

  depends_on "gcc" # Abhängigkeit von GCC
  
  def install
    # Create the bin directory if it doesn't exist
    bin.mkpath

    # Build the executable
    system "make"

    # Install the executable to the bin directory
    bin.install "bin/minesweeper"
  end

  def uninstall
    # Entfernen Sie das ausführbare Spiel
    rm bin/"minesweeper"

    # Entfernen Sie das Datenverzeichnis, falls vorhanden
    rm_rf "#{ENV['HOME']}/Library/Application Support/minesweeper"

    # Weitere Dateien oder Verzeichnisse entfernen, falls 
vorhanden
    # Zum Beispiel Konfigurationsdateien, Datenverzeichnisse usw.
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
