class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "67e672c9cdf51ca75cd6e88f0dd2e3b66357d854b6642b4d117ad14a0b593017"
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
    # Entfernen Sie das Verzeichnis, falls vorhanden
    (var/"minesweeper").rmtree

    # Entfernen Sie das ausführbare Spiel
    rm bin/"minesweeper"

   opoo "Minesweeper wurde deinstalliert."

    # Weitere Dateien oder Verzeichnisse entfernen, falls vorhanden
    # Zum Beispiel Konfigurationsdateien, Datenverzeichnisse usw.
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
