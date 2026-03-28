import itertools

CODON_AMINO_ACID_LOOKUP: dict[str, str] = {
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


def proteins(strand: str) -> list[str]:
    strands = [strand[n: n + 3] for n in range(0, len(strand), 3)]
    codons = itertools.takewhile(lambda condo: condo not in STOP_CODON, strands)
    return [CODON_AMINO_ACID_LOOKUP[codon]
            for codon in codons]
