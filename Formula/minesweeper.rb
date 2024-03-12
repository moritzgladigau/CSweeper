class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "8e7f18d95bf40528c48afd7500075fdbc3816224eac2158e4fa877e590f73d83"

  def install
    system "make" # Verwenden Sie ein Makefile, um das Spiel zu kompilieren
    bin.install "minesweeper" # Installieren Sie die ausführbare Datei in das bin-Verzeichnis
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end

