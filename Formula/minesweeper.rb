class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "dc44a156714946f4233cca75eb44e6eb5bdba72549c28ae5277007d1e647af30"
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

  def post_install
    # Erstellen Sie das Verzeichnis, falls es nicht vorhanden ist
    (var/"minesweeper").mkpath
  end

  def uninstall
    opoo "Minesweeper wurde deinstalliert."
    # Entfernen Sie das ausführbare Spiel
    rm bin/"minesweeper"

    # Entfernen Sie das Verzeichnis, falls vorhanden
    (var/"minesweeper").rmtree

    # Weitere Dateien oder Verzeichnisse entfernen, falls vorhanden
    # Zum Beispiel Konfigurationsdateien, Datenverzeichnisse usw.
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
