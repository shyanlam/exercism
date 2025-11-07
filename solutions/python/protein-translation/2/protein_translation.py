from typing import Generator

RNA_PROTEIN: dict[str, str] = {
    "AUG": "Methionine",
    "UUU": "Phenylalanine",
    "UUC": "Phenylalanine",
    "UUA": "Leucine",
    "UUG": "Leucine",
    "UCU": "Serine",
    "UCA": "Serine",
    "UCC": "Serine",
    "UCG": "Serine",
    "UAU": "Tyrosine",
    "UAC": "Tyrosine",
    "UGU": "Cysteine",
    "UGC": "Cysteine",
    "UGG": "Tryptophan",
}
STOP_CODON = {"UAA", "UAG", "UGA"}

def extract_codon(strands: str) -> Generator[str, None, None]:
    for n in range(0, len(strands), 3):
        if strands[n: n+3] in STOP_CODON:
            break
        else:
            yield strands[n: n+3]


def proteins(strand: str) -> list[str]:
    return [RNA_PROTEIN.get(codon) for codon in extract_codon(strand)]

