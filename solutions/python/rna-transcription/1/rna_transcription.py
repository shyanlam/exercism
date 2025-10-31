import string

def to_rna(dna_strand: str) -> str:
        dna_to_rna: dict[str, str] = {
            'G': 'C',
            'C': 'G',
            'T': 'A',
            'A': 'U',
        }
        tran = str.maketrans(dna_to_rna)
        return dna_strand.translate(tran)

