
"use strict";

let CheckOrientationCondition2 = require('./CheckOrientationCondition2.js')
let CheckOrientationCondition1 = require('./CheckOrientationCondition1.js')
let CheckPositionCondition = require('./CheckPositionCondition.js')
let ResetWorkpieceWeight = require('./ResetWorkpieceWeight.js')
let CalcCoord = require('./CalcCoord.js')
let OverwriteUserCartCoord = require('./OverwriteUserCartCoord.js')
let SetUserCartCoord1 = require('./SetUserCartCoord1.js')
let IsDoneBoltTightening = require('./IsDoneBoltTightening.js')
let ParallelAxis1 = require('./ParallelAxis1.js')
let SetUserCartCoord2 = require('./SetUserCartCoord2.js')
let AlignAxis1 = require('./AlignAxis1.js')
let GetUserCartCoord = require('./GetUserCartCoord.js')
let ParallelAxis2 = require('./ParallelAxis2.js')
let AlignAxis2 = require('./AlignAxis2.js')
let GetWorkpieceWeight = require('./GetWorkpieceWeight.js')
let ReleaseForce = require('./ReleaseForce.js')
let ReleaseComplianceCtrl = require('./ReleaseComplianceCtrl.js')
let SetStiffnessx = require('./SetStiffnessx.js')
let CheckForceCondition = require('./CheckForceCondition.js')
let TaskComplianceCtrl = require('./TaskComplianceCtrl.js')
let SetUserCartCoord3 = require('./SetUserCartCoord3.js')
let CoordTransform = require('./CoordTransform.js')
let SetDesiredForce = require('./SetDesiredForce.js')

module.exports = {
  CheckOrientationCondition2: CheckOrientationCondition2,
  CheckOrientationCondition1: CheckOrientationCondition1,
  CheckPositionCondition: CheckPositionCondition,
  ResetWorkpieceWeight: ResetWorkpieceWeight,
  CalcCoord: CalcCoord,
  OverwriteUserCartCoord: OverwriteUserCartCoord,
  SetUserCartCoord1: SetUserCartCoord1,
  IsDoneBoltTightening: IsDoneBoltTightening,
  ParallelAxis1: ParallelAxis1,
  SetUserCartCoord2: SetUserCartCoord2,
  AlignAxis1: AlignAxis1,
  GetUserCartCoord: GetUserCartCoord,
  ParallelAxis2: ParallelAxis2,
  AlignAxis2: AlignAxis2,
  GetWorkpieceWeight: GetWorkpieceWeight,
  ReleaseForce: ReleaseForce,
  ReleaseComplianceCtrl: ReleaseComplianceCtrl,
  SetStiffnessx: SetStiffnessx,
  CheckForceCondition: CheckForceCondition,
  TaskComplianceCtrl: TaskComplianceCtrl,
  SetUserCartCoord3: SetUserCartCoord3,
  CoordTransform: CoordTransform,
  SetDesiredForce: SetDesiredForce,
};
