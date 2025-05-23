/*
 * Copyright (c) 2016, 2023, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_JFR_RECORDER_CHECKPOINT_TYPES_JFRTYPE_HPP
#define SHARE_JFR_RECORDER_CHECKPOINT_TYPES_JFRTYPE_HPP

#include "jfr/metadata/jfrSerializer.hpp"

class FlagValueOriginConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class MonitorInflateCauseConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class GCCauseConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class GCNameConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class GCWhenConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class GCThresholdUpdaterConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class MetadataTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class MetaspaceObjectTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class ReferenceTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class NarrowOopModeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class CodeBlobTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class VMOperationTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class JfrThreadConstantSet : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class JfrThreadGroupConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class ThreadStateConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class JfrThreadConstant : public JfrSerializer {
 private:
  Thread* _thread;
  traceid _tid;
  oop _vthread;
  const char* _name;
  int _length;
  void write_name(JfrCheckpointWriter& writer);
  void write_os_name(JfrCheckpointWriter& writer, bool is_vthread);
 public:
  JfrThreadConstant(Thread* t, traceid tid, oop vthread = nullptr) :
    _thread(t), _tid(tid), _vthread(vthread), _name(nullptr), _length(-1) {}
  void serialize(JfrCheckpointWriter& writer);
};

class JfrSimplifiedVirtualThreadConstant : public JfrSerializer {
 private:
  traceid _vtid;
 public:
  JfrSimplifiedVirtualThreadConstant(traceid vtid) : _vtid(vtid) {}
  void serialize(JfrCheckpointWriter & writer);
};

class BytecodeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class CompilerTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

class NMTTypeConstant : public JfrSerializer {
 public:
  void serialize(JfrCheckpointWriter& writer);
};

#endif // SHARE_JFR_RECORDER_CHECKPOINT_TYPES_JFRTYPE_HPP
