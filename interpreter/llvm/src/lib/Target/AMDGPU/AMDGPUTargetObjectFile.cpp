//===-- AMDGPUHSATargetObjectFile.cpp - AMDGPU Object Files ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "AMDGPUTargetMachine.h"
#include "AMDGPUTargetObjectFile.h"
#include "AMDGPU.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCSectionELF.h"
#include "llvm/Support/ELF.h"
#include "Utils/AMDGPUBaseInfo.h"

using namespace llvm;

//===----------------------------------------------------------------------===//
// Generic Object File
//===----------------------------------------------------------------------===//

MCSection *AMDGPUTargetObjectFile::SelectSectionForGlobal(
    const GlobalObject *GO, SectionKind Kind, const TargetMachine &TM) const {
  auto AS = static_cast<const AMDGPUTargetMachine*>(&TM)->getAMDGPUAS();
  if (Kind.isReadOnly() && AMDGPU::isReadOnlySegment(GO, AS) &&
      AMDGPU::shouldEmitConstantsToTextSection(TM.getTargetTriple()))
    return TextSection;

  return TargetLoweringObjectFileELF::SelectSectionForGlobal(GO, Kind, TM);
}
