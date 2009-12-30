//
// Copyright (c) 2009 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef RECASTSAMPLETILEMESH_H
#define RECASTSAMPLETILEMESH_H

#include "Sample.h"
#include "DetourNavMesh.h"
#include "Recast.h"
#include "RecastLog.h"
#include "ChunkyTriMesh.h"
#include "NavMeshTesterTool.h"

class Sample_TileMesh : public Sample
{
protected:
	
	bool m_keepInterResults;
	bool m_buildAll;
	rcBuildTimes m_buildTimes; 
	
	dtNavMesh* m_navMesh;
	rcChunkyTriMesh* m_chunkyMesh;
	unsigned char* m_triflags;
	rcHeightfield* m_solid;
	rcCompactHeightfield* m_chf;
	rcContourSet* m_cset;
	rcPolyMesh* m_pmesh;
	rcPolyMeshDetail* m_dmesh;
	rcConfig m_cfg;	
	
	int m_maxTiles;
	int m_maxPolysPerTile;
	float m_tileSize;
	
	float m_tileCol[4];
	float m_tileBmin[3];
	float m_tileBmax[3];
	float m_tileBuildTime;
	float m_tileMemUsage;
	int m_tileTriCount;

	unsigned char* buildTileMesh(const float* bmin, const float* bmax, int& dataSize);
	
	void cleanup();
	
public:
	Sample_TileMesh();
	virtual ~Sample_TileMesh();
	
	virtual void handleSettings();
	virtual void handleTools();
	virtual void handleDebugMode();
	virtual void handleRender();
	virtual void handleRenderOverlay(double* proj, double* model, int* view);
	virtual void handleMeshChanged(const float* verts, int nverts,
								   const int* tris, const float* trinorms, int ntris,
								   const float* bmin, const float* bmax);
	virtual bool handleBuild();

	virtual class dtNavMesh* getNavMesh() { return m_navMesh; }
	
	void buildTile(const float* pos);
	void removeTile(const float* pos);
	void buildAllTiles();
	void removeAllTiles();
};


#endif // RECASTSAMPLETILEMESH_H
