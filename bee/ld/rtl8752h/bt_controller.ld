SECTIONS
{
    PROVIDE(vhci_has_sig_pended = 0x0004a383);
    PROVIDE(GDMA0_Channel2_Handler = 0x0004ab87);
    PROVIDE(GDMA0_Channel1_Handler = 0x0004ab9b);
    PROVIDE(BTMAC_Handler = 0x00050359);
    PROVIDE(vhci_ack = 0x00202b2c);
    PROVIDE(vhci_ack_nowake = 0x00202b30);
    PROVIDE(vhci_close = 0x00202b34);
    PROVIDE(vhci_open = 0x00202b38);
    PROVIDE(vhci_send = 0x00202b3c);
}
