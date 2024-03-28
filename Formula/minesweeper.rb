class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "76576b6ca0a16d401619cf9009ddc7e9e523593905452c0271d50f10fed0acb7"
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
