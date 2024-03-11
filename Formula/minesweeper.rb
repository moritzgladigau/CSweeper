require "formula"

class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1-beta.tar.gz"
  sha256 "640abf510f53b0deb486af956d038cda0a2691e4ba2c1f9e2e4295c5ef0460cd"

  depends_on "gcc" # Abhängigkeit von gcc

  def install
    system "gcc", "-o", "minesweeper", "src/*.c" # Kompilieren Sie Ihr Spiel
    bin.install "minesweeper" # Installieren Sie die ausführbare Datei in das bin-Verzeichnis
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end

