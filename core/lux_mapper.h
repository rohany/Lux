/* Copyright 2018 Stanford University
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _PAGERANK_MAPPER_H_
#define _PAGERANK_MAPPER_H_

#include "legion.h"
#include "default_mapper.h"
#include "../../beam_mapper.h"

using namespace Legion;
using namespace Legion::Mapping;

class LuxMapper : public BeamMapper {
public:
  LuxMapper(Machine machine, MapperRuntime *runtime, Processor local,
                const char *mapper_name);
// public:
  // virtual void select_task_options(const MapperContext ctx,
  //                                  const Task& task,
  //                                  TaskOptions& output);
  virtual void slice_task(const MapperContext ctx,
                          const Task& task,
                          const SliceTaskInput& input,
                          SliceTaskOutput& output);
  virtual Memory default_policy_select_target_memory(MapperContext ctx,
                                                     Processor target_proc,
                                                     const RegionRequirement &req);
  //virtual void map_task(const MapperContext ctx,
  //                      const Task& task,
  //                      const MapTaskInput& input,
  //                      MapTaskOutput& output);
// protected:
  unsigned int numNodes;
  std::vector<TaskSlice> gpuSlices, cpuSlices;
  std::map<unsigned, std::vector<Processor>* > allGPUs, allCPUs;
  std::map<Processor, Memory> memFBs, memZCs;
};

#endif
