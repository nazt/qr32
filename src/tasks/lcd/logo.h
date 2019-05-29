#include <Arduino.h>
static uint8_t logo[32 * 38 / 8]  = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x03,
  0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0xC0, 0x00,
  0x00, 0x00, 0x40, 0x00, 0x00, 0xC0, 0x4F, 0x00, 0x00, 0xC0, 0x7F, 0x00,
  0x00, 0xF0, 0xFF, 0x00, 0x00, 0xF8, 0xFF, 0x01, 0x00, 0xF8, 0xFF, 0x01,
  0x00, 0xEC, 0xFF, 0x03, 0x00, 0xFE, 0xFF, 0x03, 0x00, 0xFE, 0xFF, 0x07,
  0x00, 0xFE, 0xFE, 0x0F, 0x00, 0xFE, 0xFF, 0x05, 0x00, 0xFC, 0xFF, 0x03,
  0x00, 0xFE, 0xFF, 0x07, 0x00, 0x9C, 0x9F, 0x03, 0x00, 0xFC, 0xFF, 0x01,
  0x00, 0xF8, 0xFF, 0x01, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0xF0, 0xFF, 0x03,
  0x00, 0xFC, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0x0F, 0x00, 0xFF, 0xFF, 0x0F,
  0x00, 0xFF, 0xFF, 0x0D, 0x80, 0xFB, 0xFF, 0x1D, 0xB0, 0xFE, 0xFF, 0x17,
  0xF8, 0xFA, 0xFF, 0x05, 0x3C, 0xF8, 0xFF, 0x00, 0x3E, 0x30, 0xC0, 0x00,
  0x0F, 0x20, 0x40, 0x00, 0x03, 0x20, 0x40, 0x00, 0x00, 0x38, 0xC0, 0x07,
  0x00, 0x3C, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00, };



static uint8_t logo_negate[128 * 64 / 8]  = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x60, 0x1F, 0xFC, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xC0, 0x0F, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xC7, 0x83, 0x40, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x07, 0xE0, 0xF8, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x47, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x00, 0x7C, 0xFE, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x7C, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x07, 0x20, 0x08, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0xE0, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x1F, 0x00, 0x02, 0xB4, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0B, 0x00, 0x00, 0x40, 0xF9, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x12, 0x00, 0x00, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0x7F, 0x1E, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xF0, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x00, 0x80, 0xEB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xCF, 0x01, 0xE0, 0xCF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0x39, 0xFE, 0x7F, 0xFC, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x3F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x3F, 0xFE, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB8, 0x7F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0x7F, 0xDF, 0x3F, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xCF, 0x3E, 0xFC, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0x3F, 0xE8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0x9F, 0x7F, 0x38, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x20, 0xF9, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0E, 0x20, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0x7F, 0x80, 0x07, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xF9, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xBF, 0x07, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0D, 0xC3, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x48, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x40, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x60, 0xC3, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x21, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xC0, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x61, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x71, 0xE2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x71, 0xE2, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x63, 0xE2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x67, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x47, 0xF0, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, };

static uint8_t cat[40*32/8] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9,
  0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF,
  0xFF, 0xFF, 0xC0, 0xFF, 0xFD, 0xFF, 0x7F, 0x00, 0xFF, 0x57, 0xFF, 0x7F,
  0x00, 0xBA, 0xC1, 0xFF, 0x7F, 0x00, 0x7C, 0x80, 0xFE, 0x7F, 0x3C, 0x00,
  0x80, 0xFF, 0x6F, 0x3E, 0x00, 0x8C, 0xFF, 0x3F, 0x0C, 0x00, 0x80, 0xFE,
  0x3F, 0x04, 0x00, 0xC0, 0xFB, 0x7F, 0x00, 0x00, 0x40, 0x4F, 0x6F, 0x00,
  0x00, 0xC0, 0xE5, 0x7F, 0x00, 0x82, 0x00, 0xF0, 0xFF, 0x00, 0x00, 0x00,
  0xFE, 0xFF, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x01, 0x00, 0x40, 0x80, 0xBF,
  0x00, 0x00, 0x00, 0x94, 0x27, 0x00, 0x00, 0x80, 0xBD, 0x47, 0x01, 0x00,
  0xE0, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0xEF, 0xFF, 0x00, 0x00, 0x38, 0xF8,
  0x3F, 0x1C, 0x00, 0xFC, 0xE8, 0x8F, 0x9E, 0xFE, 0xDF, 0x47, 0xCF, 0xCF,
  0xFF, 0x7F, 0xEF, 0xFF, 0xE7, 0xFF, 0xFF, 0xFD, 0x8F, 0xE3, 0xFE, 0xFF,
  0xFF, 0x8F, 0xFB, 0xFF, 0xFF, 0xFF, 0xE2, 0xF9, 0xFF, 0xFF, 0xFF, 0xF3,
  0x6C, 0xFF, 0xFF, 0xFF, };


static uint8_t qr[64*64/8] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xA0, 0xBD, 0x77, 0x80, 0x3F, 0xFE, 0xFF, 0x07,
  0xE0, 0xFF, 0x7F, 0x80, 0x3F, 0xFE, 0xFF, 0x07, 0xE0, 0xB6, 0x75, 0x80,
  0x39, 0x5E, 0x44, 0x07, 0xE0, 0x00, 0x60, 0xFE, 0x31, 0x06, 0x00, 0x02,
  0x60, 0x00, 0x60, 0xFC, 0x31, 0x0E, 0x00, 0x07, 0xE0, 0x78, 0x71, 0x80,
  0x3F, 0x86, 0x15, 0x06, 0x40, 0xFC, 0x63, 0x80, 0x3F, 0xCE, 0x3F, 0x07,
  0xE0, 0xFC, 0x63, 0x80, 0x75, 0xC6, 0x3F, 0x07, 0x60, 0xF8, 0x73, 0x7C,
  0x30, 0xC6, 0x3F, 0x02, 0xE0, 0xFC, 0x63, 0x3E, 0x30, 0xCE, 0x1F, 0x07,
  0x60, 0xFC, 0x63, 0x70, 0x30, 0xC6, 0x3F, 0x07, 0x60, 0xFC, 0x63, 0x70,
  0x30, 0xC6, 0x3F, 0x02, 0x60, 0xF8, 0x63, 0x30, 0x30, 0xCE, 0x1F, 0x07,
  0xE0, 0x00, 0x60, 0x0C, 0x0C, 0x06, 0x00, 0x06, 0x60, 0x00, 0x70, 0x0C,
  0x0E, 0x06, 0x00, 0x07, 0x60, 0x22, 0x72, 0x0C, 0x22, 0x2E, 0x88, 0x07,
  0xE0, 0xFF, 0x7F, 0x8C, 0x31, 0xFE, 0xFF, 0x07, 0xE0, 0xFF, 0x7F, 0x8C,
  0x31, 0xFE, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x12,
  0x00, 0x00, 0x02, 0x00, 0xE0, 0xFF, 0xF3, 0x0F, 0xCC, 0x39, 0xC6, 0x00,
  0xE0, 0xFF, 0xE3, 0x0F, 0x8E, 0x31, 0xC6, 0x00, 0xE0, 0x63, 0x84, 0x0F,
  0xFE, 0x07, 0x1E, 0x00, 0xE0, 0x63, 0x9C, 0x0F, 0xFC, 0x07, 0x3F, 0x00,
  0xC0, 0x63, 0x8C, 0x0F, 0x7C, 0x0F, 0x3E, 0x00, 0xE0, 0xE0, 0x63, 0x7C,
  0x30, 0x3E, 0xFE, 0x00, 0xE0, 0xE0, 0x63, 0x3C, 0x30, 0x3E, 0xFE, 0x00,
  0x00, 0x80, 0x9B, 0x8F, 0xFA, 0x0E, 0x3E, 0x00, 0x00, 0x00, 0x8F, 0x8F,
  0xFF, 0x07, 0x1E, 0x00, 0x00, 0x80, 0x8F, 0x8F, 0xF7, 0x0F, 0x3E, 0x00,
  0x60, 0xE0, 0x7F, 0x0C, 0x30, 0x30, 0x18, 0x06, 0xE0, 0xE0, 0x7F, 0x0C,
  0x30, 0x30, 0x38, 0x07, 0x00, 0x00, 0x21, 0x2C, 0x30, 0x38, 0x02, 0x00,
  0x00, 0x00, 0x00, 0x7C, 0x70, 0x30, 0x06, 0x00, 0x00, 0x00, 0x00, 0x7C,
  0x30, 0x30, 0x06, 0x00, 0xE0, 0xFF, 0x7F, 0xFC, 0x8F, 0xC1, 0xF8, 0x00,
  0xE0, 0xFF, 0x7F, 0xFC, 0xCF, 0xC1, 0xF9, 0x00, 0xE0, 0x42, 0x74, 0xF4,
  0x03, 0xC0, 0xF9, 0x00, 0x60, 0x00, 0x60, 0xF0, 0x01, 0xF0, 0xFF, 0x00,
  0x60, 0x00, 0x60, 0xF0, 0x01, 0xF0, 0xFF, 0x00, 0xE0, 0xF8, 0x63, 0xFC,
  0x8F, 0xC1, 0xF8, 0x00, 0x60, 0xFC, 0x73, 0xFC, 0xCF, 0xC1, 0xF9, 0x00,
  0x60, 0xFC, 0x63, 0xDC, 0xCF, 0x81, 0xA8, 0x00, 0xC0, 0xFC, 0x63, 0x8C,
  0xFF, 0x3F, 0x06, 0x00, 0xE0, 0xFC, 0x73, 0x8C, 0xFF, 0x3F, 0x06, 0x00,
  0x60, 0xF8, 0x63, 0x0C, 0x30, 0x3E, 0x18, 0x00, 0xE0, 0xF8, 0x63, 0x0C,
  0x30, 0x3E, 0x38, 0x00, 0xE0, 0xBC, 0x71, 0x0E, 0x70, 0x2E, 0x18, 0x00,
  0x40, 0x00, 0x60, 0x7C, 0xFE, 0xC7, 0x3F, 0x00, 0xE0, 0x00, 0x60, 0x7C,
  0xFE, 0xCF, 0x3F, 0x00, 0xC0, 0xAA, 0x6D, 0x1C, 0x70, 0xC0, 0x79, 0x00,
  0xE0, 0xFF, 0x7F, 0x8C, 0x31, 0xC0, 0xF8, 0x00, 0xE0, 0xEF, 0x7D, 0x8C,
  0x31, 0xC0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };