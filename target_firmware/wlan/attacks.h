#ifndef ATTACKS_H
#define ATTACKS_H

// Utility functions
int attack_confradio(struct ath_softc_tgt *sc);
struct ath_tx_buf * attack_build_packet(struct ath_softc_tgt *sc, uint8_t *data,
			a_int32_t len, char waitack, unsigned char destmac[6], a_int32_t jam_rate_index);
void attack_free_packet(struct ath_softc_tgt *sc, struct ath_tx_buf *bf);

// Attack implementations
int attack_reactivejam(struct ath_softc_tgt *sc, unsigned char source[6],
		       unsigned int msecs, unsigned int jam_packet_length, unsigned int jam_delay_us, unsigned int jam_rate_index, unsigned int match_on_position, unsigned char match_packet_type);
int attack_constantjam_start(struct ath_softc_tgt *sc, char waitack,
			     unsigned char destmac[6], a_uint16_t length);
int attack_constantjam_stop(struct ath_softc_tgt *sc);

void ath_dma_unmap(struct ath_softc_tgt *sc, struct ath_tx_buf *bf);
void ath_filltxdesc(struct ath_softc_tgt *sc, struct ath_tx_buf *bf);
void ath_tx_freedesc(struct ath_softc_tgt *sc, struct ath_tx_buf *bf);

#endif // ATTACKS_H

