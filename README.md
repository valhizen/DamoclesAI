# DamoclesAI

> **Version 0.1.0** - Text Processing Foundation  
> A from-scratch neural network implementation in C++20

[![Version](https://img.shields.io/badge/version-0.1.0-blue.svg)]()
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)]()
[![Status](https://img.shields.io/badge/status-alpha-orange.svg)]()

---

## 🚀 Current Version: 0.1.0 (Alpha)

**What's Working:**
- ✅ Text file loading
- ✅ Word-level tokenization
- ✅ Vocabulary building with frequency analysis
- ✅ Token encoding/decoding
- ✅ Special token support

**What's NOT Working Yet:**
- ❌ Matrix operations
- ❌ Neural network layers
- ❌ Training pipeline
- ❌ Text generation

**Goal for v1.0.0:** Train a working transformer

---

## 📊 Version Roadmap

### v0.1.0 - Foundation ✅ **YOU ARE HERE**
Text processing pipeline complete

### v0.2.0 - Matrix Operations
- [ ] CPU matrix multiplication
- [ ] Element-wise operations
- [ ] Transpose, reshape utilities

### v0.3.0 - GPU Acceleration
- [ ] CUDA kernel implementation
- [ ] cuBLAS integration
- [ ] Performance benchmarking

### v0.4.0 - Embeddings
- [ ] Token embedding layer
- [ ] Positional encoding
- [ ] Embedding dimension: 512

### v0.5.0 - Attention
- [ ] Query/Key/Value projections
- [ ] Scaled dot-product attention
- [ ] Single-head implementation

### v0.6.0 - Transformer Block
- [ ] Multi-head attention (8 heads)
- [ ] Feed-forward network
- [ ] Layer normalization
- [ ] Residual connections

### v0.7.0 - Training Infrastructure
- [ ] Forward propagation
- [ ] Backpropagation
- [ ] Gradient computation

### v0.8.0 - Optimization
- [ ] Adam optimizer
- [ ] Cross-entropy loss
- [ ] Learning rate scheduling

### v0.9.0 - Generation
- [ ] Inference mode
- [ ] Temperature sampling
- [ ] Top-k/nucleus sampling

### v1.0.0 - First Release 🎯
**Complete working transformer model**

---

## 📈 Changelog

### [0.1.0] - 2025-11-27

#### Added
- `FileLoader` class for text corpus loading
- `Vocabulary` class with frequency-based building
- Word normalization (lowercase, punctuation handling)
- Token encoding to ID sequences
- Special tokens: `<PAD>`, `<UNK>`, `<BOS>`, `<EOS>`
- Vocabulary serialization to disk
- Shakespeare corpus integration

#### Testing
- Encoding test cases
- Unknown word handling
- Vocabulary statistics output

---
