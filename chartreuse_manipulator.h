#pragma once

#include <maya/MPxManipulatorNode.h>
#include <maya/MDagPath.h>

class ChartreuseContext;

class ChartreuseManipulator : public MPxManipulatorNode {
public:
  ChartreuseManipulator();
  void setup(ChartreuseContext* ctx, MDagPath newHighlight = MDagPath());
  MDagPath highlightedDagPath() const;

  virtual void postConstructor() override;
  virtual MStatus doMove(M3dView& view, bool& refresh) override;
  MStatus doMoveError(bool& refresh);
  virtual void draw(M3dView &view,
    const MDagPath &path,
    M3dView::DisplayStyle style,
    M3dView::DisplayStatus status) override;
  virtual void preDrawUI(const M3dView &view) override;
  virtual void drawUI(MHWRender::MUIDrawManager &drawManager,
    const MHWRender::MFrameContext &frameContext) const override;

  static void* creator();
  static MStatus initialize();
  static const MTypeId id;

private:
  ChartreuseContext* _ctx;
  MDagPath _highlight;
};
